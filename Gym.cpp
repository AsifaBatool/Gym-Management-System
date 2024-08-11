#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_MEMBERS = 100;
const int MAX_CLASSES = 100;
const int MAX_INVOICES = 100;
const int MAX_WORKOUTS = 100;
const int MAX_NOTIFICATIONS = 100;
const int MAX_MEALS = 100;
const int MAX_BOOKINGS = 100;
const int MAX_USERS = 100;

// User Class
class User
{
private:
    string username;
    string password;
    bool isAdmin;

public:
    User(const string &username = "", const string &password = "", bool isAdmin = false)
    {
        this->username = username;
        this->password = password;
        this->isAdmin = isAdmin;
    }

    string getUsername() const { return username; }
    bool login(const string &username, const string &password) const
    {   
        if(this->username == username && this->password == password){
            return true;
        }
        return false;
    }
    void signUp(const string &username, const string &password)
    {
        this->username = username;
        this->password = password;
        this->isAdmin = false;
    }
};

// Membership Class
class Membership
{
private:
    string plan;
    double price;

public:
    Membership(const string &plan = "", double price = 0.0)
    {
        this->plan = plan;
        this->price = price;
    }

    string getPlan() const { return plan; }
    double getPrice() const { return price; }
    void upgradePlan(const string &newPlan, double newPrice)
    {
        plan = newPlan;
        price = newPrice;
    }
    void downgradePlan(const string &newPlan, double newPrice)
    {
        plan = newPlan;
        price = newPrice;
    }
};

// Attendance Class
class Attendance
{
private:
    string members[MAX_MEMBERS];
    int attendanceRecord[MAX_MEMBERS];
    int memberCount;

public:
    Attendance() : memberCount(0)
    {
        for (int i = 0; i < MAX_MEMBERS; ++i)
        {
            attendanceRecord[i] = 0;
        }
    }

    void markAttendance(const string &username)
    {
        for (int i = 0; i < memberCount; ++i)
        {
            if (members[i] == username)
            {
                attendanceRecord[i]++;
                return;
            }
        }

        if (memberCount < MAX_MEMBERS)
        {
            members[memberCount] = username;
            attendanceRecord[memberCount] = 1;
            memberCount++;
        }
    }

    int getAttendance(const string &username) const
    {
        for (int i = 0; i < memberCount; ++i)
        {
            if (members[i] == username)
            {
                return attendanceRecord[i];
            }
        }
        return 0;
    }
};

// Schedule Class
class Schedule
{
private:
    string classNames[MAX_CLASSES];
    string timeSlots[MAX_CLASSES];
    int classCount;

public:
    Schedule() : classCount(0) {}

    void createClass(const string &className, const string &timeSlot)
    {
        if (classCount < MAX_CLASSES)
        {
            classNames[classCount] = className;
            timeSlots[classCount] = timeSlot;
            classCount++;
        }
    }

    void manageClass(const string &className, const string &newTimeSlot)
    {
        for (int i = 0; i < classCount; ++i)
        {
            if (classNames[i] == className)
            {
                timeSlots[i] = newTimeSlot;
                return;
            }
        }
    }

    string getClassSchedule(const string &className) const
    {
        for (int i = 0; i < classCount; ++i)
        {
            if (classNames[i] == className)
            {
                return timeSlots[i];
            }
        }
        return "Class not found.";
    }
};

// Billing Class
class Billing
{
private:
    string members[MAX_INVOICES];
    double invoices[MAX_INVOICES];
    int invoiceCount;

public:
    Billing() : invoiceCount(0) {}

    void addInvoice(const string &username, double amount)
    {
        if (invoiceCount < MAX_INVOICES)
        {
            members[invoiceCount] = username;
            invoices[invoiceCount] = amount;
            invoiceCount++;
        }
    }

    double getInvoice(const string &username) const
    {
        for (int i = 0; i < invoiceCount; ++i)
        {
            if (members[i] == username)
            {
                return invoices[i];
            }
        }
        return 0.0;
    }

    void payInvoice(const string &username)
    {
        for (int i = 0; i < invoiceCount; ++i)
        {
            if (members[i] == username)
            {
                invoices[i] = 0.0;
                return;
            }
        }
    }
};

// Workout Class
class Workout
{
private:
    string members[MAX_WORKOUTS];
    string workouts[MAX_WORKOUTS];
    string goals[MAX_WORKOUTS];
    int workoutCount;

public:
    Workout() : workoutCount(0) {}

    void trackWorkout(const string &username, const string &workout)
    {
        if (workoutCount < MAX_WORKOUTS)
        {
            members[workoutCount] = username;
            workouts[workoutCount] = workout;
            workoutCount++;
        }
    }

    string getWorkoutLog(const string &username) const
    {
        for (int i = 0; i < workoutCount; ++i)
        {
            if (members[i] == username)
            {
                return workouts[i];
            }
        }
        return "No workout log found.";
    }

    void setGoal(const string &username, const string &goal)
    {
        for (int i = 0; i < workoutCount; ++i)
        {
            if (members[i] == username)
            {
                goals[i] = goal;
                return;
            }
        }

        if (workoutCount < MAX_WORKOUTS)
        {
            members[workoutCount] = username;
            goals[workoutCount] = goal;
            workoutCount++;
        }
    }

    string getGoal(const string &username) const
    {
        for (int i = 0; i < workoutCount; ++i)
        {
            if (members[i] == username)
            {
                return goals[i];
            }
        }
        return "No goal set.";
    }
};

// Notification Class
class Notification
{
private:
    string members[MAX_NOTIFICATIONS];
    string messages[MAX_NOTIFICATIONS];
    int notificationCount;

public:
    Notification() : notificationCount(0) {}

    void addNotification(const string &username, const string &message)
    {
        if (notificationCount < MAX_NOTIFICATIONS)
        {
            members[notificationCount] = username;
            messages[notificationCount] = message;
            notificationCount++;
        }
    }

    string getNotifications(const string &username) const
    {
        string userNotifications;
        for (int i = 0; i < notificationCount; ++i)
        {
            if (members[i] == username)
            {
                userNotifications += messages[i] + "\n";
            }
        }
        return userNotifications.empty() ? "No notifications." : userNotifications;
    }
};

// Meal Class
class Meal
{
private:
    string members[MAX_MEALS];
    string meals[MAX_MEALS];
    int mealCount;

public:
    Meal() : mealCount(0) {}

    void trackMeal(const string &username, const string &meal)
    {
        if (mealCount < MAX_MEALS)
        {
            members[mealCount] = username;
            meals[mealCount] = meal;
            mealCount++;
        }
    }

    string getMealLog(const string &username) const
    {
        for (int i = 0; i < mealCount; ++i)
        {
            if (members[i] == username)
            {
                return meals[i];
            }
        }
        return "No meal log found.";
    }
};

// PersonalTrainer Class
class PersonalTrainer
{
private:
    string members[MAX_BOOKINGS];
    string trainerNames[MAX_BOOKINGS];
    string dates[MAX_BOOKINGS];
    string times[MAX_BOOKINGS];
    int bookingCount;

public:
    PersonalTrainer() : bookingCount(0) {}

    void bookSession(const string &username, const string &trainerName, const string &date, const string &time)
    {
        if (bookingCount < MAX_BOOKINGS)
        {
            members[bookingCount] = username;
            trainerNames[bookingCount] = trainerName;
            dates[bookingCount] = date;
            times[bookingCount] = time;
            bookingCount++;
        }
    }

    string getBooking(const string &username) const
    {
        for (int i = 0; i < bookingCount; ++i)
        {
            if (members[i] == username)
            {
                return "Trainer: " + trainerNames[i] + ", Date: " + dates[i] + ", Time: " + times[i];
            }
        }
        return "No booking found.";
    }
};

// GymManagementSystem Class
class GymManagementSystem
{
private:
    User users[MAX_USERS];
    int userCount;
    Membership memberships[MAX_USERS];
    Attendance attendance;
    Schedule schedule;
    Billing billing;
    Workout workout;
    Notification notification;
    Meal meal;
    PersonalTrainer personalTrainer;

    void memberMenu(const string &username)
    {
        string choice;
        while (true)
        {
            cout << "\n1. Manage Membership\n2. Attendance\n3. Schedule\n4. Billing\n5. Workout\n6. Notifications\n7. Meals\n8. Personal Trainer\n9. Display Details\n10. Logout\nChoose an option: ";
            cin >> choice;
            if (choice == "1")
            {
                manageMembership(username);
            }
            else if (choice == "2")
            {
                manageAttendance(username);
            }
            else if (choice == "3")
            {
                manageSchedule();
            }
            else if (choice == "4")
            {
                manageBilling(username);
            }
            else if (choice == "5")
            {
                manageWorkout(username);
            }
            else if (choice == "6")
            {
                viewNotifications(username);
            }
            else if (choice == "7")
            {
                manageMeals(username);
            }
            else if (choice == "8")
            {
                managePersonalTrainer(username);
            }
            else if (choice == "9")
            {
                displayUserDetails(username);
            }
            else if (choice == "10")
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    void manageMembership(const string &username)
    {
        string plan;
        double price;
        cout << "Current membership plan: " << memberships[userCount].getPlan() << ", Price: " << memberships[userCount].getPrice() << "\n";
        cout << "Enter new plan: ";
        cin >> plan;
        cout << "Enter new price: ";
        cin >> price;
        memberships[userCount].upgradePlan(plan, price);
        cout << "Membership updated.\n";
    }

    void manageAttendance(const string &username)
    {
        attendance.markAttendance(username);
        cout << "Attendance marked for " << username << ". Total attendance: " << attendance.getAttendance(username) << "\n";
    }

    void manageSchedule()
    {
        string className, timeSlot;
        cout << "Enter class name: ";
        cin >> className;
        cout << "Enter time slot: ";
        cin >> timeSlot;
        schedule.createClass(className, timeSlot);
        cout << "Class scheduled.\n";
    }

    void manageBilling(const string &username)
    {
        double amount;
        cout << "Enter amount to add to invoice: ";
        cin >> amount;
        billing.addInvoice(username, amount);
        cout << "Invoice added. Current invoice amount: $" << billing.getInvoice(username) << "\n";
    }

    void manageWorkout(const string &username)
    {
        string workoutLog;
        cout << "Enter workout log: ";
        cin.ignore();
        getline(cin, workoutLog);
        workout.trackWorkout(username, workoutLog);
        cout << "Workout logged.\n";

        string goal;
        cout << "Enter your workout goal: ";
        getline(cin, goal);
        workout.setGoal(username, goal);
        cout << "Goal set.\n";
    }

    void viewNotifications(const string &username)
    {
        cout << "Current Notifications:\n"
             << notification.getNotifications(username);
        string message;
        cout <<"\nEnter your message: ";
        cin.ignore();
        getline(cin, message);
        notification.addNotification(username, message);
        cout << "New Notifications:\n"
             << notification.getNotifications(username);
    }

    void manageMeals(const string &username)
    {
        string mealLog;
        cout << "Enter meal log: ";
        cin.ignore();
        getline(cin, mealLog);
        meal.trackMeal(username, mealLog);
        cout << "Meal logged.\n";
    }

    void managePersonalTrainer(const string &username)
    {
        string trainerName, date, time;
        cout << "Enter trainer name to book session with: ";
        cin >> trainerName;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;
        cout << "Enter time (HH:MM): ";
        cin >> time;
        personalTrainer.bookSession(username, trainerName, date, time);
        cout << "Session booked with " << trainerName << " on " << date << " at " << time << ".\n";
    }

    void displayUserDetails(const string &username)
    {
        cout << "\nUser Details for " << username << ":\n";
        cout << "Membership Plan: " << memberships[userCount].getPlan() << ", Price: " << memberships[userCount].getPrice() << "\n";
        cout << "Total Attendance: " << attendance.getAttendance(username) << "\n";
        cout << "Workout Log: " << workout.getWorkoutLog(username) << "\n";
        cout << "Workout Goal: " << workout.getGoal(username) << "\n";
        cout << "Meal Log: " << meal.getMealLog(username) << "\n";
        cout << "Personal Trainer Booking: " << personalTrainer.getBooking(username) << "\n";
        cout << "Notifications: " << notification.getNotifications(username) << "\n";
        cout << "Invoice Amount: $" << billing.getInvoice(username) << "\n";
    }

public:
    GymManagementSystem() : userCount(0) {}

    void run()
    {
        string choice;
        while (true)
        {
            cout << "1. Login\n2. Sign Up\n3. Exit\nChoose an option: ";
            cin >> choice;
            if (choice == "1")
            {
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                for (int i = 0; i < userCount; ++i)
                {
                    if (users[i].login(username, password))
                    {
                        cout << "Login successful!\n";
                        memberMenu(username);
                        break;
                    }
                }
                cout << "Invalid credentials. Please try again.\n";
            }
            else if (choice == "2")
            {
                string username, password;
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;

                if (userCount < MAX_USERS)
                {
                    users[userCount].signUp(username, password);
                    memberships[userCount] = Membership("Basic", 50.0); // Assign a default membership
                    userCount++;
                    cout << "Sign up successful! You can now log in.\n";
                }
                else
                {
                    cout << "User limit reached. Cannot sign up more users.\n";
                }
            }
            else if (choice == "3")
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main()
{

    cout << "\n**************************************\n";
    cout << "*  Welcome to Gym Management System  *\n";
    cout << "**************************************\n\n";
    GymManagementSystem gym;
    gym.run();
    return 0;
}

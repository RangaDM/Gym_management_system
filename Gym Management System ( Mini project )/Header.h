#pragma once
#include <iostream>
using namespace std;
class User
{
public:
    User()
    {
        name = "";
        address = "";
        age = 0;
        height = 0;
        weight = 0;
        BMI = 0;
        ID = 0;
        status = "Not Set";
        dietPlans = "Not Set";
    }
    User(string n, string a, int ag, float h, float w)
    {
        name = n;
        address = a;
        age = ag;
        height = h;
        weight = w;

        CalcBMI();
        dietPlan();

    }

    string getName() const {
        return name;
    }
    void setName(string n) {
        name = n;
    }

    string getAddress() const {
        return address;
    }
    void setAddress(string a) {
        address = a;
    }

    int getAge() const {
        return age;
    }
    void setAge(int ag) {
        age = ag;
    }

    float getHeight() const {
        return height;
    }
    void setHeight(float h) {
        height = h;
        CalcBMI();

    }

    float getWeight() const {
        return weight;
    }
    void setWeight(float w) {
        weight = w;
        CalcBMI();
    }
    float getBMI() const {
        return BMI;
    }
    void setID(int userID) {
        ID = userID;
    }

    int getID() {
        return ID;
    }



    void printUser()
    {
        cout << "\n\n\t\tId\t\t:\t" << ID << endl;
        cout << "\n\t\tName\t\t:\t" << name << endl;
        cout << "\n\t\tAddress\t\t:\t" << address << endl;
        cout << "\n\t\tAge\t\t:\t" << age << endl;
        cout << "\n\t\tHeight\t\t:\t" << height << endl;
        cout << "\n\t\tWeight\t\t:\t" << weight << endl;
        cout << "\n\t\tBMI\t\t:\t" << BMI << endl;
        cout << "\n\t\tStatus\t\t:\t" << status << endl;
    }

    void dietPlan()
    {
        cout << "\n\n\t\tDiet Plan for : " << name << " (ID: " << ID << ")\n" << endl;
        if (status == "Overweight")
        {
            //diet plan for overweight
            cout << "\n\t\tYou are overweight. Here is a diet plan to help you lose weight:\n" << endl;
            cout << "\t\t- Reduce your calorie intake by eating smaller portions and \n\t   limiting your intake of high-calorie foods." << endl;
            cout << "\t\t- Choose foods that are high in fiber and protein, as they can help you feel full for longer." << endl;
            cout << "\t\t- Drink plenty of water to stay hydrated.\n" << endl;
            cout << "\t\t- A coach who specializes in weight loss and nutrition, who can \n\t   create personalized diet plans and exercise programs to help \n\t   members lose weight and \n\t   improve their health." << endl;
            cout << "\n\t\t** Johnson - +94 7555-1234 **\n" << endl;
        }
        else if (status == "Underweight")
        {
            //diet plan for underweight
            cout << "\n\t\tYou are underweight. Here is a diet plan to help you gain weight:\n" << endl;
            cout << "\t\t- Eat frequent, small meals throughout the day." << endl;
            cout << "\t\t- Choose nutrient-dense foods that are high in calories, protein, \n\t   and healthy fats." << endl;
            cout << "\t\t- Add extra toppings to your meals, such as cheese, nuts, and avocado.\n" << endl;
            cout << "\t\t- A coach who specializes in strength training and building muscle mass, \n\t   who can help members gain weight and improve their overall fitness levels." << endl;
            cout << "\n\t\t** Lee - +94 7555-2222 ** \n" << endl;
        }
        else if (status == "Normal weight")
        {
            //diet plan for normal weight
            cout << "\n\t\tYou are at a healthy weight. Here are some tips to maintain your weight:\n" << endl;
            cout << "\t\t- Eat a balanced diet that includes a variety of fruits, vegetables, whole grains, \n\t   lean protein, and healthy fats." << endl;
            cout << "\t\t- Limit your intake of processed and sugary foods." << endl;
            cout << "\t\t- Stay active by doing regular exercise.\n" << endl;
            cout << "\t\t- A coach who specializes in overall fitness and wellness, who can help \n\t   members maintain a healthy weight and lifestyle through a \n\t   variety of exercise programs and nutritional guidance." << endl;
            cout << "\n\t\t** Kevin - +94 7555-9999 **\n" << endl;
        }
        else if (status == "Obesity")
        {
            //diet plan for obesity
            cout << "\n\t\tYou are at obesity. Here is a diet plan to help you lose weight:\n" << endl;
            cout << "\t\t- Reduce your calorie intake by eating smaller portions and \n\t   limiting your intake of high-calorie foods." << endl;
            cout << "\t\t- Choose foods that are high in fiber and protein, as they can help \n\t   you feel full for longer." << endl;
            cout << "\t\t- Drink plenty of water to stay hydrated.\n" << endl;
            cout << "\t\t- A coach who specializes in obesity management and lifestyle change, \n\t   who can help members address the underlying factors contributing to \n\t   their weight issues and create sustainable lifestyle changes for \n\t   long-term success." << endl;
            cout << "\n\t\t** Lisa - +94 7555-7777 **\n" << endl;
        }
        else
        {
            cout << "\n\t\tNo assigned diet plans\n" << endl;
        }
    }
    void CalcBMI()
    {
        BMI = weight / (height * height);

        if (BMI >= 30)
        {
            status = "Obesity";
        }
        else if (BMI < 30 && BMI >= 25)
        {
            status = "Overweight";
        }
        else if (BMI < 25 && BMI >= 18.5)
        {
            status = "Normal weight";
        }
        else
        {
            status = "Underweight";
        }
    }


private:
    string name;
    string address;
    int age;
    float height;
    float weight;
    float BMI;
    int ID;
    string status;
    string dietPlans;
};
class Node {
public:
    User data;
    Node* next;
    Node* prev;

    Node(User u) {
        data = u;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void setID() {
        Node* current = head;
        for (int i = 0; i < size; i++) {
            current->data.setID(i + 1);
            current = current->next;
        }
    }

    void insertFirst(User u) {
        Node* newNode = new Node(u);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
        size++;
        setID();
    }
    void insertLast(User u) {
        Node* newNode = new Node(u);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }

        size++;
        setID();
    }
    void insertAt(int index, User u) {
        if (index < 0) return;
        Node* newNode = new Node(u);
        Node* current = head;
        for (int i = 0; i < index - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) return;
        if (current->prev == NULL) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            newNode->prev = NULL;
        }
        else if (current->next == NULL) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else {
            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
        setID();
        size++;
    }
    void deleteFirst() {
        if (head == NULL) return;
        if (head->next == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }
        setID();
        size--;
    }
    void deleteLast() {
        if (tail == NULL) return;
        if (tail->prev == NULL) {
            head = NULL;
            tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        setID();
        size--;
    }
    void deleteAt(int index)
    {
        if (index < 0) return;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        Node* temp = current;
        (current->prev)->next = temp->next;
        (current->next)->prev = temp->prev;
        delete temp;
        size--;
    }

    void printAllUsers() {
        Node* current = head;
        while (current != NULL) {
            User u = current->data;
            cout << " \tID: " << u.getID() << "\t|Name: " << u.getName() << "\t\t|Address: " << u.getAddress() << endl;
            current = current->next;
        }
    }
    void printUserAt(int index) {
        if (index < 0 || index >= size) return;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        User u = current->data;
        cout << "Name: " << u.getName() << ", Age: " << u.getAge() << ", Address: " << u.getAddress() << ", Height: " << u.getHeight() << ", Weight: " << u.getWeight() << ", BMI: " << u.getBMI() << endl;
    }

    Node* getAt(int index) {
        if (index < 0 || index >= size) return NULL;
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
};
DoublyLinkedList InitialGymList()
{

    DoublyLinkedList gymUsers;

    User newUser1("Max", "New York", 25, 1.8, 70);
    User newUser2("John", "Chicago", 28, 1.7, 75);
    User newUser3("Tom", "Los Angeles", 20, 1.8, 67);
    User newUser4("Mike", "Houston", 45, 1.7, 78);
    User newUser5("Mark", "Phoenix", 30, 1.8, 70);
    User newUser6("Steve", "Philadelphia", 25, 1.7, 75);
    User newUser7("Bob", "San Antonio", 30, 1.8, 95);
    User newUser8("David", "San Diego", 15, 1.7, 85);
    User newUser9("Edward", "Dallas", 20, 1.8, 78);
    User newUser10("Daniel", "San Jose", 25, 1.6, 70);
    User newUser11("Frank", "Austin", 32, 1.6, 100);
    User newUser12("George", "Jacksonville", 27, 1.8, 110);
    User newUser13("Jerry", "San Francisco", 30, 1.7, 120);
    User newUser14("Joe", "Columbus", 45, 1.7, 130);
    User newUser15("Kevin", "Fort Worth", 60, 1.8, 140);
    User newUser16("Brian", "Charlotte", 65, 1.7, 150);

    gymUsers.insertLast(newUser1);
    gymUsers.insertLast(newUser2);
    gymUsers.insertLast(newUser3);
    gymUsers.insertLast(newUser4);
    gymUsers.insertLast(newUser5);
    gymUsers.insertLast(newUser6);
    gymUsers.insertLast(newUser7);
    gymUsers.insertLast(newUser8);
    gymUsers.insertLast(newUser9);
    gymUsers.insertLast(newUser10);
    gymUsers.insertLast(newUser11);
    gymUsers.insertLast(newUser12);
    gymUsers.insertLast(newUser13);
    gymUsers.insertLast(newUser14);
    gymUsers.insertLast(newUser15);
    gymUsers.insertLast(newUser16);

    return gymUsers;
}
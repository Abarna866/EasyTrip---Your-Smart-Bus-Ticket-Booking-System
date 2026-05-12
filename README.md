# ✈️ Easy Trip - Bus Ticket Booking System

> A Java-based Bus Ticket Booking System that allows users to search buses, book tickets, manage reservations, and generate booking details through a simple and user-friendly interface.

---

## 🚀 Features

* 🔍 Search available buses by source and destination
* 🪑 Seat selection and booking
* 👤 User registration and login system
* 🎫 Ticket generation with booking details
* 💳 Fare calculation and payment simulation
* 📅 Journey date management
* ❌ Ticket cancellation feature
* 🛠 Admin panel for managing buses and schedules
* 📊 Booking history and customer details
* 💾 Database connectivity using MySQL

---

## 🏗️ Tech Stack

### Frontend

* Java Swing / JavaFX

### Backend

* Java

### Database

* MySQL

### Tools Used

* NetBeans / Eclipse / IntelliJ IDEA
* JDBC Driver

---

## 📂 Project Modules

### 1. User Module

* User Registration
* User Login
* Search Bus
* Book Ticket
* View Booking History

### 2. Admin Module

* Add Bus Details
* Update Bus Timings
* Manage Routes
* View Bookings

### 3. Ticket Module

* Seat Allocation
* Ticket Generation
* Cancellation Process

---

## 🖥️ System Architecture

```text
+-------------------+
|   User Interface  |
+-------------------+
          |
          v
+-------------------+
|   Java Backend    |
| (Business Logic)  |
+-------------------+
          |
          v
+-------------------+
|     MySQL DB      |
+-------------------+
```

---

## 📸 Screenshots

### Login Page

* User authentication screen

### Bus Search Page

* Search buses based on location and date

### Seat Booking Page

* Select seats and confirm booking

### Ticket Page

* Displays booking confirmation and ticket details

---

## ⚙️ Installation Steps

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/your-username/Easy-Trip-Bus-Ticket-Booking-System.git
```

### 2️⃣ Open Project

* Open the project in NetBeans / Eclipse / IntelliJ

### 3️⃣ Setup Database

Create a MySQL database:

```sql
CREATE DATABASE easytrip;
```

Import the SQL file:

```sql
easytrip.sql
```

### 4️⃣ Configure JDBC

Update database credentials inside:

```java
DBConnection.java
```

Example:

```java
String url = "jdbc:mysql://localhost:3306/easytrip";
String username = "root";
String password = "your_password";
```

### 5️⃣ Run the Project

* Run the `Main.java` file

---

## 📊 Database Tables

* Users
* Buses
* Routes
* Bookings
* Payments
* Seats

---

## 🔐 Future Enhancements

* Online payment gateway integration
* QR Code based tickets
* Live bus tracking
* Mobile application support
* AI-based seat recommendation
* Email/SMS notifications

---

## 🎯 Project Objective

The main objective of this project is to simplify the bus ticket booking process digitally and reduce manual reservation work by providing an efficient and automated booking system.

---

## 👨‍💻 Team Members

* Abar D
* Akshaya
* Sanjay
* FUTURE FORGE Team

---

## 📜 License

This project is developed for educational and learning purposes.

---

## 🤝 Contribution

Contributions, suggestions, and improvements are welcome.

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub.

---

GitHub README files usually include project overview, features, installation steps, architecture, and usage instructions so that recruiters or developers can quickly understand the project.

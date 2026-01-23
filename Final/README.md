[PROJE ADI: My Personal Notes App]
Video Demo: [Buraya YouTube Linkini Gelecek]
Description:

This is my final project for CS50x. It is a web-based personal note-taking application designed to provide users with a clean, minimal, and secure way to store their thoughts, daily tasks, or important reminders.

The project is built using Python and the Flask framework, with a SQLite database on the backend to manage user data and note content. On the frontend, I utilized HTML, CSS, and Bootstrap to ensure the application is responsive and user-friendly across both desktop and mobile devices.
Why this project?

I chose to build a note-taking app because, while it seems simple, it covers the core principles of web development: CRUD (Create, Read, Update, Delete) operations. This project allowed me to practice managing relational databases, handling user sessions for security, and designing an interface that is both functional and aesthetically pleasing.
Features:

    User Authentication: Users can register for an account and log in securely. Password security is handled using werkzeug.security for hashing.

    Personalized Content: Once logged in, users can only see, add, and delete their own notes. This is managed through SQL queries filtered by user_id.

    Real-time Interaction: Users can add new notes through a simple form and see them appear instantly on their dashboard.

    Responsive Design: Thanks to Bootstrap, the app looks great on phones, tablets, and computers.

File Structure:

    app.py: The heart of the application. It contains all the Flask routes and the logic for interacting with the database. It handles user login, registration, adding notes, and deleting notes.

    notes.db: The SQLite database file. It contains two tables: users (to store login credentials) and notes (to store the actual note content linked to a specific user).

    helpers.py: Contains the login_required decorator, which ensures that only logged-in users can access their notes.

    templates/: This directory contains all the HTML files.

        layout.html: The base template containing the navbar and common head elements.

        index.html: The main dashboard where notes are displayed and the input form lives.

        login.html and register.html: The authentication pages.

    static/: Contains styles.css for custom styling that goes beyond the basic Bootstrap theme.

Challenges:

The most challenging part was ensuring that one user could not delete another user's notes by manually manipulating the POST request. I solved this by adding a secondary check in the SQL DELETE query to match both the note_id and the session["user_id"].

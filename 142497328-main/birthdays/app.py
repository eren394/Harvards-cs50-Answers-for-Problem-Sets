import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session

app = Flask(__name__)

# Veritabanı bağlantısı
db = SQL("sqlite:///birthdays.db")

@app.after_request
def after_request(response):
    """Yanıtların önbelleğe alınmasını engelle"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Formdan gelen verileri al
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Veritabanına ekle
        if name and month and day:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", name, month, day)

        return redirect("/")

    else:
        # Veritabanındaki tüm doğum günlerini çek
        birthdays = db.execute("SELECT * FROM birthdays")
        # index.html'e bu verileri gönder
        return render_template("index.html", birthdays=birthdays)

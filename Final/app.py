@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    if request.method == "POST":
        # Yeni not ekle
        note = request.form.get("note")
        if note:
            db.execute("INSERT INTO notes (user_id, content) VALUES (?, ?)", session["user_id"], note)
        return redirect("/")
    else:
        # Kullanıcının notlarını çek ve göster
        notes = db.execute("SELECT * FROM notes WHERE user_id = ? ORDER BY timestamp DESC", session["user_id"])
        return render_template("index.html", notes=notes)

@app.route("/delete", methods=["POST"])
@login_required
def delete():
    # Notu silme işlemi
    note_id = request.form.get("note_id")
    db.execute("DELETE FROM notes WHERE id = ? AND user_id = ?", note_id, session["user_id"])
    return redirect("/")

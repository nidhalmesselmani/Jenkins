from app import app

@app.route("/")
def index():
    return "hi"

@app.route("/about")
def about():
    return "<h1 style='color: red'> Abouddt!!! </h1>"

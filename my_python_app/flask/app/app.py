import os

from flask import Flask

app = Flask(__name__)

@app.route("/")
def index():
    return "hi"

@app.route("/about")
def about():
    return "<h1 style='color: red'> Abouddt!!! </h1>"

if __name__ == "__main__":
    print('hi')
    app.run()
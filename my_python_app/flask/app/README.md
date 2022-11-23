 python -m venv env
# windows

.\env\Scripts\activate

# linux 
source env/bin/activate 

# install flask
pip install flask

# run flask app
python app.py

OR

set FLASK_APP=app.py
set FLASK_ENV=development

install python-dotenv to use .env

# to put all your dependecies in a file
pip freeze > requirements.txt 
pip install -r requirements.txt 
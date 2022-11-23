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

install python-dotenv
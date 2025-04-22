rem call by csript //d source\scripts\install_mkl.bat

if not exist "build\" mkdir build 
cd build
python -m venv venv
venv\Scripts\activate
pip install mkl-static


### Setup Repo to Start Compiling/Building

#### MacOS/Linux/WSL
```bash
python3 -m venv venv
source venv/bin/activate
python3 -m pip install qmk
# Set the QMK home to point to this repository
qmk setup -H .
# Install both lists of python packages
pip3 install -r requirements.txt
pip3 install -r requirements-dev.txt
# Check QMK Installation
qmk hello # Output should be "Hello, World!"
qmk --version
```

### Get back into the virtual environment after Setup
```bash
source venv/bin/activate
```

### Compile/Build a Keyboard Command
```bash
qmk compile -kb <KEYBOARD-NAME> -km vial
```

Example:
```bash
# Outputs .uf2 file in hidden .build folder
qmk compile -kb zm_k9 -km vial
```



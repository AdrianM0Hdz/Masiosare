"""
This program is designed to automatically build and deploy the code to the
aduino. Originaly we were going to build both a batch and a shell script but decided
to write a a python script for simplicity.
The Fully Qualified Board Name and Main script name are both env variables with default Values.
"""

import os
import sys

def main():
    FQBN = os.environ.get('FQBN') or 'arduino:avr:uno'
    PORT = os.environ.get('PORT') or 'COM3'
    MAIN_SCRIPT_NAME = os.environ.get('MAIN_SCRIPT_NAME')
    
    if MAIN_SCRIPT_NAME == None:
        cwdir = os.getcwd()
        if sys.platform == 'win32':
            MAIN_SCRIPT_NAME = cwdir.split('\\')[-1] + '.ino'
        else:
            MAIN_SCRIPT_NAME = cwdir.split('/')[-1] + '.ino'
    # build
    os.system(f'arduino-cli compile --fqbn {FQBN} {MAIN_SCRIPT_NAME}')    
    # upload
    os.system(f'arduino-cli upload -p {PORT} --fqbn {FQBN} {MAIN_SCRIPT_NAME}')

if __name__ == "__main__":
    main()

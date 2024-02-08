#!/usr/bin/env python3

import sys
import subprocess
from pathlib import Path

def CheckRollNo(rollNo):
    if len(rollNo)!=13:
        print(f"Error: Incorrect roll number {rollNo}. Your roll number must have 13 characters.")
        print("  e.g. 2021A7PS9999G, 2020B4A79999G")
        exit()

def CheckAllFilesExist(lab,rollNo,ques,testcase):
    success=True

    CheckRollNo(rollNo)
    necessaryFiles = [f"{lab}_{ques}_{rollNo}.cpp", f"{lab}_{ques}_{testcase}_input.txt", f"{lab}_{ques}_{testcase}_output.txt"]
    
    for file in necessaryFiles:
        file_path = Path(file)
        if not file_path.is_file():
            print(f"Error: Unable to find '{file_path}' in the current directory.")
            success=False
    
    if success==False:
        exit()
    return necessaryFiles


def RunTestCase(lab,rollNo,ques,testcase):
    success = 0
    
    cppFile, tcInputFile, tcOutputFile = CheckAllFilesExist(lab,rollNo,ques,testcase)
    cppOutput = f"{lab}_{ques}_{rollNo}"

    # Command to compile the C++ program 
    compile_command = ["g++", cppFile, "-o", cppOutput] 
     
    # Command to execute the compiled program 
    run_command = [f"./{cppOutput}"] 
     
    # Compile the C++ program 
    compile_process = subprocess.run(compile_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE) 
     
    # Check if the compilation was successful 
    if compile_process.returncode == 0: 
        print(f"{cppFile} compiled successful.") 
        # Run the compiled program 
        with open( f"{tcInputFile}", 'rb' ) as f:
            data = f.read()

        run_process = subprocess.run(run_command,input=data, stdout=subprocess.PIPE, stderr=subprocess.PIPE) 
         
        # Get the output and error messages from the program 
        output = run_process.stdout.decode() 
        error = run_process.stderr.decode() 
         
        # Print the output and error messages 
        print(f"Output of {cppFile}:")
        print(output)
        print(error)

        with open(f"{tcOutputFile}", 'r' ) as f:
            expectedOutput = f.read()
        
        if output.strip() == expectedOutput.strip():
            success = 1
    else: 
        # Print the compilation error messages 
        print("Compilation failed.") 
        print(compile_process.stderr.decode())

    return success

def main():
#    Next include lab number also 
    if len(sys.argv) != 5:
        print("Error: Some command-line arguments are missing.")
        print("Usage: ./RunTestCase.py <Lab_number> <Question_number> <Roll_number> <TestCase_number>")
        print("   eg. ./RunTestCase.py L1 Q1 2021A7PS9999G T1")
        exit()
    lab,ques,rollNo,testcase = [a.upper() for a in sys.argv[1:]]
    
    success=RunTestCase(lab,rollNo,ques,testcase)
    if success==1:
        print(f"Test case {testcase} passed.")
    else:
        print(f"Test case {testcase} failed.")
   

if __name__=="__main__":
    main()

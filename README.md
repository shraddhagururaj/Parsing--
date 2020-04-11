
# Parsing Different formats in C 

Simple Parsers in C for csv and json format


### Installing

The JSON parser uses a library json-c which can be installed on a Linux system using the following command: <br />
**sudo apt install libjson-c-dev**



## Running the tests
After downloading the C codes and the sample test files, run:

1. **CSV Parser**:  gcc csvparser.c -Wall -o csv_parser <br />
                    ./csv_parser 
2. **JSON Parser**: gcc jsonparser.c -ljson-c -o testjson <br />
                    ./testjson
                


from os import listdir
from os.path import isfile, join
import subprocess

path_to_tests = "./tests/"
path_to_examples = "./examples/"
path_to_executable = "./out/a.out"

test_files = [file for file in listdir(path_to_tests) if (isfile(join(path_to_tests, file)))]

example_files = [file for file in listdir(path_to_examples) if (isfile(join(path_to_examples, file)))]

def compare(example, test):
    out = subprocess.run([path_to_executable, test], stdout=subprocess.PIPE)
    output = out.stdout.decode("utf-8")
    example_contents = open(example, 'r').read()
    # print("OUT:")
    # print(output.replace(' ', '*'))
    # print("-----------------")
    # print(example_contents.replace(' ', '*'))
    return output == example_contents;

tests_amount = len(test_files)
wrong_tests = 0
for i in range(len(test_files)):
    tests_amount
    if not compare(path_to_examples + example_files[i], path_to_tests + test_files[i]):
        print("Wrong at " + example_files[i] + " : " + test_files[i])
        wrong_tests+=1

print("Finished. %d wrong from %d tests" % (wrong_tests, tests_amount))
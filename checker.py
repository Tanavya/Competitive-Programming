import os, subprocess, sys, timeit
directory = os.getcwd()

arguments = sys.argv[1:]
count = len(arguments)
file = arguments[0]
time_limit = 0
if count > 1:
    time_limit = float(arguments[1])
else:
    time_limit = 5
scoring = []
scoring_provided = False
if count > 2:
    scoring_provided = True
    n_subtask = int(arguments[2])
    for i in range(n_subtask):
        scoring.append(float(arguments[3+i]))


subprocess.call(["g++", "-std=c++14", "-Wl,-stack_size", "-Wl,2000000000", directory + "/" +file])
subtasks = [x for x in [x[0] for x in os.walk(directory)][1:] if "Subtask" in x]
inputs = []
outputs = []
for subtask in subtasks:
    curr_subtask_in = []
    curr_subtask_out = []
    for filename in os.listdir(subtask):
        if filename.endswith("in"):
            curr_subtask_in.append(subtask+"/"+filename)
        elif filename.endswith("out"):
            curr_subtask_out.append(subtask+"/"+filename)
    inputs.append(curr_subtask_in)
    outputs.append(curr_subtask_out)

total = len(inputs)
score = 0


inp = ""
def test():
    os.system("./a.out < " + inp + " > my.out")

def compare(file1, file2):
    with open(file1) as f1:
        with open(file2) as f2:
            for line1, line2 in zip(f1, f2):
                if line1.strip() != line2.strip():
                    return False
        with open(file1) as f1:
            with open(file2) as f2:
                cnt1 = 0
                cnt2 = 0
                for line1 in f1:
                    cnt1 += len(line1.strip()) > 0
                for line2 in f2:
                    cnt2 += len(line2.strip()) > 0
                if cnt1 != cnt2:
                    return False
    return True

for subtask in range(len(inputs)):
    sub_in = inputs[subtask]
    sub_out = outputs[subtask]
    AC = True
    print "Subtask ", subtask+1
    for i in range(len(sub_in)):
        inp = sub_in[i]
        out = sub_out[i]
        t = timeit.Timer("test()", "from __main__ import test")
        time_taken = t.timeit(number=1)
        print "Execution successful. Time taken:", time_taken
        if time_taken > time_limit:
            print "Test Case " + str(i+1) + ": " + "TLE"
            AC = False
        elif compare('my.out', out):
            print "Test Case " + str(i+1) + ": " + "AC"
        else:
            print "Test Case " + str(i+1) + ": " + "WA"
            AC = False
    if AC:
        if scoring_provided:
            score += scoring[subtask]
        else:
            score += 1
if scoring_provided:
    print "Score:", score
else:
    print "Score:", (float(score)/total) * 100

import os, subprocess
directory = os.getcwd()
file = raw_input()
subprocess.call(["g++", "-std=c++14", directory+ "/" +file])

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
for subtask in range(len(inputs)):
    sub_in = inputs[subtask]
    sub_out = outputs[subtask]
    AC = True
    print "Subtask ", subtask+1
    for i in range(len(sub_in)):
        inp = sub_in[i]
        out = sub_out[i]
        os.system("./a.out < " + inp + " > my.out")
        with open("my.out") as f:
            my_out = f.read().replace("\n", "")
        with open(out) as f:
            expected_out = f.read().replace("\n", "")
        if my_out == expected_out:
            print "Test Case " + str(i+1) + ": " + "AC"
        else:
            print "Test Case " + str(i+1) + ": " + "WA"
            AC = False
    if AC:
        score += 1
print "Score:", (float(score)/total) * 100

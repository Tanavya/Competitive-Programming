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

print compare("test1.txt", "test2.txt")
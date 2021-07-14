file = open("Miestai.txt","r")
#f = open("Duomenys.txt", "a")
Counter = 0

# Reading from file
Content = file.read()
CoList = Content.split("\n")

for i in CoList:
    if i:
        if i.split(",")[0].find(' ') == -1:
            if len(i.split(",")[0]) < 19:
                Length = 20 - len(i.split(",")[0])
                ss = ""
                for j in range(Length):
                    ss = ss + " "
                string = i.split(",")[0] + ss + i.split(",")[1] + "\n"
                print(string)
                #f.write(string)
                Counter = Counter + 1

print(Counter)

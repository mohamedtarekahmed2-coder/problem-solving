string = input()
result = ""
for i in string:
    if i.isspace():
        result += "..."
    else:
        result += i
print (result)
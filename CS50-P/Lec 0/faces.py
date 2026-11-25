def main():
    string = input()
    print (convert(string))
    
def convert(string):
    result = ""
    i = 0
    while i < len(string):
        if string[i:i + 2] == ":(":
            result += "🙁"
            i+=2
        elif string[i:i + 2] == ":)":
            result += "🙂"
            i+=2
        else:
            result += string[i]
            i+=1
    return result
    
main()
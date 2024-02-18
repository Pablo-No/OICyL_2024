n = int(input())
for _ in range(n):
    s = input()
    if len(s) != 9: print("otros")
    elif s[0:3] in ["803","806","807","905","907"]: print("$$$")
    elif s[0] in ["9","8"] and s[1] not in ["0", "9"]: print("fijo")
    elif s[0] in ["6","7"]: print("movil")
    else: print("otros")
code = "lucro"                    #adivinha
l = len(code)                     #lenght
c = False                         #current

#algoritmo errado
state = True
print("="*(l+10))
print("#"*l, " "*5, l)
while state == True:
    def getword():
        print("="*(l+9))
        c = input()
        if len(c) != l:
            print("quantia indevida")
            return(False)
        else:
            return(c)
    def analise(current, reserva):
        if current == code:
            return(True)
        else:
            out = []
            for i in range(0,l):
                if current[i] in reserva:
                    if current[i] == code[i]:
                        out.append("o")
                    else:
                        out.append("x")
                    reserva = reserva.replace(current[i], "0", 1) 
                else:
                    out.append("-")
            print(''.join(out))
            return(False)
    if c == False:
        c = getword()
    else:
        r = code
        if analise(c, r) == False:
            c = getword()
        else:
            print("="*(l+10))
            print("Vitória")
            print("="*(l+10))
            state = False
#! python3
# filnamn: emjo2109_3.3_v1.py
# Skrivet av: Emil Jons
# Skapat datum: 2021-09-26
# Senast ändrat: 2021-09-26
# Kurs: Grundläggande Datavetenskap
# Handledare: Nayeb Maleki
# Beskrivning: Ett program som kontrollerar om det inmatade året är ett skottår eller inte. 

år = int(input("Ange år" ))
if(år % 4 == 0):
    if(år % 100 == 0):
        if(år % 400 == 0):
            print("Skottår")
        else: 
            print("Inte skottår")
    else: 
        print("Skottår")
else: 
    print("Inte skottår")
Element(0x00 "Plastic leadless chip carrier with pin socket" "" "PLCC32X" 350 400 0 100 0x00)
# PLCC - 44 is a  special case, pad 1 in inner row
(
# top left row
Pin(450 250 62 35 "1" 0x101) 
	Pin(350 150 62 35 "2" 0x01) 
Pin(350 250 62 35 "3" 0x01) 
	Pin(250 150 62 35 "4" 0x01) 
#left row
Pin(150 250 62 35 "5" 0x01) 
	Pin(250 250 62 35 "6" 0x01) 
Pin(150 350 62 35 "7" 0x01) 
	Pin(250 350 62 35 "8" 0x01) 
Pin(150 450 62 35 "9" 0x01) 
	Pin(250 450 62 35 "10" 0x01) 
Pin(150 550 62 35 "11" 0x01) 
	Pin(250 550 62 35 "12" 0x01) 
Pin(150 650 62 35 "13" 0x01)
# bottom row
Pin(250 750 62 35 "14" 0x01) 
	Pin(250 650 62 35 "15" 0x01) 
Pin(350 750 62 35 "16" 0x01) 
	Pin(350 650 62 35 "17" 0x01) 
Pin(450 750 62 35 "18" 0x01) 
	Pin(450 650 62 35 "19" 0x01) 
Pin(550 750 62 35 "20" 0x01)
# right row
Pin(650 650 62 35 "21" 0x01) 
	Pin(550 650 62 35 "22" 0x01) 
Pin(650 550 62 35 "23" 0x01) 
	Pin(550 550 62 35 "24" 0x01) 
Pin(650 450 62 35 "25" 0x01) 
	Pin(550 450 62 35 "26" 0x01) 
Pin(650 350 62 35 "27" 0x01) 
	Pin(550 350 62 35 "28" 0x01) 
Pin(650 250 62 35 "29" 0x01)
# top rigth row
Pin(550 150 62 35 "30" 0x01) 
	Pin(550 250 62 35 "31" 0x01) 
Pin(450 150 62 35 "32" 0x01)
	ElementLine(0 0 800 0 20)
	ElementLine(800 0 800 900 20)
	ElementLine(800 900 0 900 20)
	ElementLine(0 900 0 0 20)
	ElementLine(0 100 100 0 10)
	ElementLine(350 0 400 50 10)
	ElementLine(400 50 450 0 10)
	Mark(400 150)
#------------------------------------------------------------------------
# all other sockets, currently 20,52,68 and 84 pins
)

#
#    Ludnośc protestująca przeciwko
#   nieuczciwemu przyznawaniu nagród
# za komentarze (2019, dekoloryzowane)
#                       \ ###\ ##
#           .       \o   \ ##| ##
#               .    \\  | ###\ #
#           *  ,  .  |\'  \ #####
#         o/o/o/o/  ====   |#####
#

from cyklib import circular_shift, give_answer

sqrt_n = 50

k = 0
u = [circular_shift(0)]
r = None
for i in range(1, sqrt_n):
	k += 1
	x = circular_shift(1)
	if x in u:
		r = k
		break
	u.append(x)

while r is None:
	k += sqrt_n
	x = circular_shift(sqrt_n)
	if x in u:
		r = k - u.index(x)

give_answer(r)
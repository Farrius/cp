from jutge import read
from PIL import Image, ImageDraw

n = read(int)

img = Image.new("RGB", (90 * n, 90 * n))
dib = ImageDraw.Draw(img)

def color (i, j, op):
    if ((i + j + op) % 2 == 0):
        return "Black"
    else:
        return "White"
#la base
for i in range(n):
    for j in range(n):
        dib.rectangle([(i * 90, j * 90), (i * 90 + 89, j * 90 + 89)], color(i, j, 0))

for i in range(n//2):
    #arriba
    dib.rectangle([(n//2 * 90 + 5, i * 90 + 65), (n//2 * 90 + 24, i * 90 + 84)], color(i, n//2, 1));
    dib.rectangle([(n//2 * 90 + 65, i * 90 + 65), (n//2 * 90 + 84, i * 90 + 84)], color(i, n//2, 1));
    #abajo
    dib.rectangle([(n//2 * 90 + 5, (n//2 + i + 1) * 90 + 5), (n//2 * 90 + 24, (n//2 + i + 1) * 90 + 24)], color((n//2 + i + 1), n//2, 1));
    dib.rectangle([(n//2 * 90 + 65, (n//2 + i + 1) * 90 + 5), (n//2 * 90 + 84, (n//2 + i + 1) * 90 + 24)], color((n//2 + i + 1), n//2, 1));
    #izquierda
    dib.rectangle([(i * 90 + 65, n//2 * 90 + 5), (i * 90 + 84, n//2 * 90 + 24)], color(i, n//2, 1));
    dib.rectangle([(i * 90 + 65, n//2 * 90 + 65), (i * 90 + 84, n//2 * 90 + 84)], color(i, n//2, 1));
    #derecha
    dib.rectangle([((n//2 + 1 + i) * 90 + 5, n//2 * 90 + 5), ((n//2 + 1 + i) * 90 + 24, n//2 * 90 + 24)], color((n//2 + 1 + i), n//2, 1));
    dib.rectangle([((n//2 + 1 + i) * 90 + 5, n//2 * 90 + 65), ((n//2 + 1 + i) * 90 + 24, n//2 * 90 + 84)], color((n//2 + 1 + i), n//2, 1));
    for j in range(i):
        #arriba izquierda
        up_iz = n//2 - i + j
        dib.rectangle([(up_iz * 90 + 5, i * 90 + 65), (up_iz * 90 + 24, i * 90 + 84)], color(i, up_iz, 1))
        dib.rectangle([(up_iz * 90 + 65, i * 90 + 5), (up_iz * 90 + 84, i * 90 + 24)], color(i, up_iz, 1))
        #arriba derecha
        up_de = n//2 + i - j
        dib.rectangle([(up_de * 90 + 5, i * 90 + 5), (up_de * 90 + 24, i * 90 + 24)], color(i, up_de, 1))
        dib.rectangle([(up_de * 90 + 65, i * 90 + 65), (up_de * 90 + 84, i * 90 + 84)], color(i, up_de, 1))
        #abajo izquierda
        ba_iz_y = n - i - 1
        ba_iz_x = n//2 - j - 1
        dib.rectangle([(ba_iz_x * 90 + 5, ba_iz_y * 90 + 5), (ba_iz_x * 90 + 24, ba_iz_y * 90 + 24)], color(ba_iz_x, ba_iz_y, 1))
        dib.rectangle([(ba_iz_x * 90 + 65, ba_iz_y * 90 + 65), (ba_iz_x * 90 + 84, ba_iz_y * 90 + 84)], color(ba_iz_x, ba_iz_y, 1))
        #abajo derecha
        ba_de_y = n - i - 1
        ba_de_x = n//2 + j + 1
        dib.rectangle([(ba_de_x * 90 + 5, ba_de_y * 90 + 65), (ba_de_x * 90 + 24, ba_de_y * 90 + 84)], color(ba_de_x, ba_de_y, 1))
        dib.rectangle([(ba_de_x * 90 + 65, ba_de_y * 90 + 5), (ba_de_x * 90 + 84, ba_de_y * 90 + 24)], color(ba_de_x, ba_de_y, 1))
#save
img.save("output.png")

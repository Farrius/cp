from jutge import read
from PIL import Image, ImageDraw

r, g, b = read(int, int, int)

img = Image.new("RGB", (900, 300))
dib = ImageDraw.Draw(img)

for i in range(6):
   dib.rectangle([(150 * i, 0), (150 * i + 149, 299)], (int((4 - i) * r/5), int((4 - i) * g/5), int((4 - i) * b/5)))

img.save("output.png")

import cv2                                                      #Import OpenCV image processing libraries 
from PIL import Image                                           #Pillow library used to import Image functions
from pytesseract import pytesseract as tess                     #we use Pytesseract OCR open source library for our image processing
import serial                                                   #Pyserial library used for Serial communication with WeMos
import time                                                     


camera = cv2.VideoCapture(0)                                    #instructs camera to start video capturing
text=""


while True:
    _,image=camera.read()                                       #reads image
    cv2.imshow('Detect Text',image)                             #opens camera as another dialog box
    if cv2.waitKey(1)& 0xFF==ord('s'):                          #Only captures image when we press 'S' in our keyboard
        cv2.imwrite('testimg1.jpg',image)                       #saves image as a JPEG file
        break
camera.release()
cv2.destroyAllWindows()



#def tesseract():
tess.pytesseract_cmd= r'/usr/local/bin/tesseract'             #this calls upon pytesseract OCR and assigns its Path 
image_path = 'testimg1.jpg'
text=tess.image_to_string(Image.open(image_path))             #uses built-in function of Pytesseract to convert image into an ASCII string
print(text[:-1])                                              #prints the string on terminal

#tesseract()




# arduino = serial.Serial(port = 'COM6', timeout = 0)
# time.sleep(2)

ser = serial.Serial('/dev/cu.usbserial-1420', 9600)          #Here Python starts communicating with WeMos
time.sleep(3)

string = text                                             

ser.write(string.encode("utf-8"))                           #Python sends the string captured by the camera to the Serial Monitor of WeMos 

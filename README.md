# Steganography in C
Steganography is the practice of hiding private or sensitive information within something that appears to be nothing out of the usual. Steganography involves hiding information so it appears that no information is hidden at all. If a person or persons views the object that the information is hidden inside he or she will have no idea that there is any hidden information, therefore the person will not attempt to decrypt the information.
Here, we implement the Steganography in C to write/encrypt the message into an image and later, verify by decoding the message from the image.

## Steps to run the program
1. Clone the repository
2. $ cd Steganography
3. $ make
4. $ ./writeMessage "<secret message>" image.ppm
  * Escape special characters with `\`
  * out.ppm will be the modified file
5. $ ./readMessage out.ppm 

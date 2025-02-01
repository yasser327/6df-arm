import cv2
import numpy as np
import serial
ser = serial.Serial('COM9', 9600)  # Change 'COM3' to the correct port


# Define the lower and upper bounds for the blue color in HSV
lower_blue = np.array([100, 50, 50])
upper_blue = np.array([140, 255, 255])


# Define the boundaries of the nine squares on the A4 paper (210mm x 297mm)
paper_width, paper_height = 297, 210  # in mm
square_width, square_height = paper_width // 3, paper_height // 3

squares = [
    ((0, 0), (square_width, square_height)), ((square_width, 0), (2 * square_width, square_height)), ((2 * square_width, 0), (paper_width, square_height)),
    ((0, square_height), (square_width, 2 * square_height)), ((square_width, square_height), (2 * square_width, 2 * square_height)), ((2 * square_width, square_height), (paper_width, 2 * square_height)),
    ((0, 2 * square_height), (square_width, paper_height)), ((square_width, 2 * square_height), (2 * square_width, paper_height)), ((2 * square_width, 2 * square_height), (paper_width, paper_height))
]
def check_object_position(object_center):
    # Check which square the object is in
    for i, ((x1, y1), (x2, y2)) in enumerate(squares):
        if x1 <= object_center[0] <= x2 and y1 <= object_center[1] <= y2:
            return i + 1  # Return square index from 1 to 9
    return -1  # Object is not in any square

def check_object_position(object_center):
    # Check which square the object is in
    for i, ((x1, y1), (x2, y2)) in enumerate(squares):
        if x1 <= object_center[0] <= x2 and y1 <= object_center[1] <= y2:
            return i
    return -1  # Object is not in any square

cap = cv2.VideoCapture(0)  # Use the camera (change the index if you have multiple cameras)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Convert the frame to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Threshold the HSV image to get only yellow colors
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    # Find contours in the mask
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw the squares on the frame
    for square in squares:
        cv2.rectangle(frame, square[0], square[1], (255, 0, 0), 2)

    # Process each contour
    for contour in contours:
        # Get the bounding rectangle of the contour
        x, y, w, h = cv2.boundingRect(contour)
        object_center = (x + w // 2, y + h // 2)  # Calculate the center of the object

        # Check if the object is in any of the squares
        square_index = check_object_position(object_center)

        # Highlight the square if the object is in it
        if square_index != -1:
            cv2.rectangle(frame, squares[square_index][0], squares[square_index][1], (0, 255, 0), -1)
         # Send the square index to Arduino via serial
        if square_index != -1:
            ser.write(f'{square_index}\n'.encode())

    cv2.imshow('Frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
print(i)
cv2.destroyAllWindows()

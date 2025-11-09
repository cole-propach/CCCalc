from ultralytics import YOLO
import cv2
import json
import os


# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Build full paths to your files
model_path = os.path.join(script_dir, "best.pt")
image_path = os.path.join(script_dir, "image.jpg")

# Load the model
new_mod = YOLO(model_path)

# Run prediction
results = new_mod.predict(image_path, conf=0.5)


# Show results. Comment out when on the server
#cv2.imshow("result", results[0].plot())
#cv2.waitKey(0)

# print/return relevant data as json.
# Maybe a json of box positions + guessed id.

nametoID = {
     "1Chicken": 2,
     "1Cow": 3,
     "1Pig": 4,
     "2B_Chickens": 5,
     "2B_Cows": 6,
     "2B_Pigs": 7,
     "2Blue_1": 8,
     "2Blue_2": 9,
     "2Blue_3": 10,
     "2Blue_Sold_1": 11,
     "2Blue_Sold_2": 12,
     "2Blue_Sold_3": 13,
     "2Chickens_1": 14,
     "2Chickens_2": 15,
     "2Chickens_3": 16,
     "2Cows_1": 17,
     "2Cows_2": 18,
     "2Cows_3": 19,
     "2Pigs_1": 20,
     "2Pigs_2": 21,
     "2Pigs_3": 22,
     "2Pink_Sold_1": 23,
     "2Pink_Sold_2": 24,
     "2Pink_Sold_3": 25,
     "2R_Chickens": 26,
     "2R_Cows": 27,
     "2R_Pigs": 28,
     "2Red_1": 29,
     "2Red_2": 30,
     "2Red_3": 31,
     "2Sheep_1": 32,
     "2Sheep_2": 33,
     "2Sheep_3": 34,
     "2Sheep_4": 35,
     "2Sheep_5": 36,
     "2Sheep_6": 37,
     "2W_Chickens": 38,
     "2W_Cows": 39,
     "2W_Pigs": 40,
     "2Wild_Sold1": 41,
     "2Wild_Sold2": 42,
     "2Wild_Sold3": 43,
     "2Y_Chickens": 44,
     "2Y_Cows": 45,
     "2Y_Pigs": 46,
     "2Yellow_1": 47,
     "2Yellow_2": 48,
     "2Yellow_3": 49,
     "2Yellow_Sold_1": 50,
     "2Yellow_Sold_2": 51,
     "2Yellow_Sold_3": 52,
     "3Animals_1": 53,
     "3Animals_2": 54,
     "3Animals_3": 55,
     "3Animals_4": 56,
     "3Animals_5": 57,
     "3Animals_6": 58,
     "3Animals_7": 59,
     "3Animals_8": 60,
     "3Animals_9": 61,
     "3Animals_10": 62,
     "3Animals_11": 63,
     "3Animals_12": 64,
     "3Animals_W": 65,
     "3Blue": 66,
     "3Chickens": 67,
     "3Cows": 68,
     "3Pigs": 69,
     "3Red": 70,
     "3Sheep_1": 71,
     "3Sheep_2": 72,
     "3Sheep_3": 73,
     "3Sheep_4": 74,
     "3Sheep_Sold_1": 75,
     "3Sheep_Sold_2": 76,
     "3Sheep_Sold_3": 77,
     "3Sheep_Sold_4": 78,
     "3Yellow": 79,
     "Mix_1": 80,
     "Mix_2": 81,
     "Mix_3": 82,
     "Mix_4": 83,
     "Mix_5": 84,
     "Mix_6": 85,
     "Barn_Side": 86,
     "Barn_Up": 87,
     "Opposite_Side": 88,
     "Opposite_Up": 89,
     "Silo_Blue": 90,
     "Silo_Red": 91,
     "Silo_Yellow": 92,
}

output = []

for box in results[0].boxes:
     xywh = box.xywh
     cardNumber = box.cls
     output.append([int(xywh[0][0]), int(xywh[0][1]), nametoID[results[0].names[int(cardNumber)]]])

json_data = json.dumps(output)

print(output)


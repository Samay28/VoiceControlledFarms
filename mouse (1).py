import cv2
import mediapipe as mp
import pyautogui

cam = cv2.VideoCapture(0)
# to detect eyes or specific thing,we will pass refine landmarks as true
face_mesh = mp.solutions.face_mesh.FaceMesh(refine_landmarks = True)
screen_w, screen_h = pyautogui.size()
while True:
    _, frame = cam.read()
    frame = cv2.flip(frame,1)
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    output = face_mesh.process(rgb_frame)
    landmarks_points = output.multi_face_landmarks
    frame_h, frame_w, _ = frame.shape
    
    # render landmarks on the face
    if landmarks_points:
        # keep only one face
        # to detech face  -> landmark range -> 474 : 478
        landmarks = landmarks_points[0].landmark
        for id, landmark in enumerate(landmarks[474:478]):
            x = int(landmark.x * frame_w)
            y = int(landmark.y * frame_h)
            cv2.circle(frame, (x,y), 3, (0, 255, 0))
            if id == 1:
                screen_x = screen_w / frame_w * x
                screen_y = screen_h / frame_h * y
                pyautogui.moveTo(screen_x, screen_y)
        

        # detect blink
        left = [landmarks[145], landmarks[159]]
        for landmark in left:
            x = int(landmark.x * frame_w)
            y = int(landmark.y * frame_h)
            cv2.circle(frame, (x,y), 3, (0, 255, 0))

        # Check if eyes are closed (blink detected) by measuring vertical distance between landmarks
        # print(left[0].y - left[1].y)
        # if (left[0].y - left[1].y) < 0.02:
        #     print('click')
        #     pyautogui.click()
        #     pyautogui.sleep(1)

    # print(landmarks_points)

    cv2.imshow("Eye Controlled Mouse", frame)

    cv2.waitKey(1)


    # step2
    # detect face


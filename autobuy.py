import pyautogui, pyperclip, time
time.sleep(2)
for i in range(1000):
    pyautogui.press("a")
    for k in range(6):
        pyautogui.press("space")
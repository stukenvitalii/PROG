import tkinter as tk
from tkinter import filedialog
import pandas as pd
from sklearn.linear_model import LinearRegression

def load_dataset():
    filename = filedialog.askopenfilename(filetypes=[("CSV Files", "*.csv")])
    if filename:
        dataset = pd.read_csv(filename)
        X = dataset[['X', 'Z']]
        Y = dataset['Y']
        model.fit(X, Y)
        result_label.configure(text="Dataset loaded and model trained successfully!")
    else:
        result_label.configure(text="No file selected.")

def predict_value():
    x_value = float(x_entry.get())
    z_value = float(z_entry.get())
    prediction = model.predict([[x_value, z_value]])
    result_label.configure(text="Predicted value: {}".format(prediction[0]))

# Создание окна приложения
window = tk.Tk()
window.title("Linear Regression App")
window.geometry("400x300")

# Кнопка загрузки файла
file_button = tk.Button(window, text="Load Dataset", command=load_dataset)
file_button.pack(pady=10)

# Ввод значений X и Z
x_frame = tk.Frame(window)
x_frame.pack()

x_label = tk.Label(x_frame, text="Enter X value:")
x_label.pack(side=tk.LEFT)
x_entry = tk.Entry(x_frame)
x_entry.pack(side=tk.LEFT)

z_frame = tk.Frame(window)
z_frame.pack()

z_label = tk.Label(z_frame, text="Enter Z value:")
z_label.pack(side=tk.LEFT)
z_entry = tk.Entry(z_frame)
z_entry.pack(side=tk.LEFT)

# Кнопка предсказать
predict_button = tk.Button(window, text="Predict", command=predict_value)
predict_button.pack(pady=10)

# Вывод предсказанного значения
result_label = tk.Label(window, text="")
result_label.pack()

# Создание модели линейной регрессии
model = LinearRegression()

# Запуск главного цикла приложения
window.mainloop()

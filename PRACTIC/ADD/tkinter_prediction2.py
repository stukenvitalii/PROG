import tkinter as tk
from tkinter import filedialog
import pandas as pd
from sklearn.linear_model import LinearRegression, LogisticRegression

import tkinter as tk
from tkinter import filedialog
from tkinter import ttk
import pandas as pd
from sklearn.linear_model import LinearRegression, LogisticRegression

def load_dataset():
    global model
    filename = filedialog.askopenfilename(filetypes=[("CSV Files", "*.csv")])
    if filename:
        dataset = pd.read_csv(filename)
        if 'Y' in dataset.columns:
            X = dataset[['X', 'Z']]
            Y = dataset['Y']
            model_type = model_choice.get()  # Get the selected model type from the dropdown menu

            if model_type == 'Linear Regression':
                model = LinearRegression()
                model.fit(X, Y)
                result_label.configure(text="Dataset loaded and Linear Regression model trained successfully!")
            elif model_type == 'Logistic Regression':
                model = LogisticRegression()
                model.fit(X, Y)
                result_label.configure(text="Dataset loaded and Logistic Regression model trained successfully!")
            else:
                result_label.configure(text="Invalid model selection.")
        else:
            result_label.configure(text="Invalid dataset. 'Y' column not found.")
    else:
        result_label.configure(text="No file selected.")

def predict_value():
    x_value = float(x_entry.get())
    z_value = float(z_entry.get())

    if model:
        if isinstance(model, LogisticRegression):
            prediction = model.predict([[x_value, z_value]])
            predicted_class = int(prediction[0])
            result_label.configure(text="Predicted class: {}".format(predicted_class))
        else:
            prediction = model.predict([[x_value, z_value]])
            result_label.configure(text="Predicted value: {}".format(prediction[0]))
    else:
        result_label.configure(text="Model not trained yet.")

# Create the Tkinter application window
window = tk.Tk()
window.title("Model Selection")

# Create a dropdown menu for model selection
model_choice = ttk.Combobox(window, values=["Linear Regression", "Logistic Regression"])
model_choice.set("Linear Regression")
model_choice.pack()

# Rest of the code remains unchanged
# ...

def choose_model():
    model_type = model_var.get()
    if model_type == "Linear Regression":
        model = LinearRegression()
    elif model_type == "Logistic Regression":
        model = LogisticRegression()
    else:
        model = None
    return model

# Создание окна приложения
window = tk.Tk()
window.title("Regression App")
window.geometry("400x350")

# Кнопка загрузки файла
file_button = tk.Button(window, text="Load Dataset", command=load_dataset)
file_button.pack(pady=10)

# Выбор модели
model_label = tk.Label(window, text="Select Model:")
model_label.pack()

model_var = tk.StringVar()
model_var.set("Linear Regression")

model_options = ["Linear Regression", "Logistic Regression"]
model_dropdown = tk.OptionMenu(window, model_var, *model_options)
model_dropdown.pack(pady=5)

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

# Запуск главного цикла приложения
window.mainloop()

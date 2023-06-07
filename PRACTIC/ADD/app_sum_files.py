import tkinter as tk
from tkinter import filedialog
import pandas as pd
import numpy as np
from sklearn import linear_model
import matplotlib.pyplot as plt

class SummationApp(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()
    
    def predict(filename):
        df = pd.read_csv('data.csv')    # upload data
        

        DATA = df.loc[:,['x','z']].values
        result= df.loc[:,['results']].values

        # learn the model
        reg = linear_model.LinearRegression()
        reg.fit(DATA,result)

        #prediction
        predicted_Y = reg.predict(DATA)
        #print('predicted results for all DATA colum is:', predicted_Y)

        # Y= a(x) + b(z) + c
        coefficients= reg.coef_
        interception = reg.intercept_

        print('coef is', coefficients)            # coeffiecents
        print('intercept_ is ' , interception)       # interception


        # СЃР»СѓС‡Р°Р№РЅС‹Рµ Р·РЅР°С‡РµРЅРёСЏ X Рё Z.
        #               ([[ X,  Z]])
        S = reg.predict([[0.6, 1.1]])   # predicted y
        print('РџСЂРµРґСЃРєР°Р·Р°РЅРёРµ Y :',S )

    def create_widgets(self):
        # создаем фреймы для блоков выбора файлов и текстовых областей
        self.left_frame = tk.Frame(self)
        self.left_frame.pack(side="left", padx=10, pady=10)

        self.right_frame = tk.Frame(self)
        self.right_frame.pack(side="right", padx=10, pady=10)

        # создаем блоки выбора файлов и кнопку сложения
        # self.first_file_button = tk.Button(self.left_frame, text="Выбрать первый файл (X)", command=self.select_first_file)
        # self.first_file_button.pack(padx=10, pady=10)

        # self.second_file_button = tk.Button(self.left_frame, text="Выбрать второй файл(Z)", command=self.select_second_file)
        # self.second_file_button.pack(padx=10, pady=10)

        self.sum_button = tk.Button(self.left_frame, text="выбрать файл с данными", command=self.sum_numbers)
        self.sum_button.pack(padx=10, pady=10)

        self.sum_button = tk.Button(self.left_frame, text="Предсказание", command=self.sum_numbers)
        self.sum_button.pack(padx=10, pady=10)

        # создаем текстовые области для отображения значений чисел
        self.first_number_label = tk.Label(self.right_frame, text="X=")
        self.first_number_label.pack(padx=10, pady=10)

        self.first_number_text = tk.Text(self.right_frame, width=20, height=1)
        self.first_number_text.pack(padx=10, pady=10)

        self.second_number_label = tk.Label(self.right_frame, text="Z=")
        self.second_number_label.pack(padx=10, pady=10)

        self.second_number_text = tk.Text(self.right_frame, width=20, height=1)
        self.second_number_text.pack(padx=10, pady=10)

       # self.third_number_label = tk.Label(self.right_frame, text="Y=")
       # self.third_number_label.pack(padx=10, pady=10)

      #  self.second_number_text = tk.Text(self.right_frame, width=20, height=1)
      #  self.second_number_text.pack(padx=10, pady=10)

        # создаем метку для отображения результата
        self.result_label = tk.Label(self, text="предсказание значения Y будет здесь", font=("Arial", 16))
        self.result_label.pack(pady=20)

    def select_first_file(self):
        self.first_file_path = filedialog.askopenfilename()
        with open(self.first_file_path, "r") as f:
            first_number = int(f.readline())
        self.first_number_text.delete(1.0, tk.END)
        self.first_number_text.insert(tk.END, str(first_number))

    def select_second_file(self):
        self.second_file_path = filedialog.askopenfilename()
        with open(self.second_file_path, "r") as f:
            second_number = int(f.readline())
        self.second_number_text.delete(1.0, tk.END)
        self.second_number_text.insert(tk.END, str(second_number))

    def sum_numbers(self):
        with open(self.first_file_path, "r") as f:
            first_number = int(f.readline())
        with open(self.second_file_path, "r") as f:
            second_number = int(f.readline())
        result = first_number + second_number
        self.result_label.config(text="Результат: {}".format(result))

root = tk.Tk()
root.title("предсказание")
app = SummationApp(master=root)
app.mainloop()
import csvReader

text_to_csv = csvReader.TextToCSV('input1.txt', ',', 'output1.csv')
text_to_csv.convert()

csv_to_text = csvReader.CSVToText('input2.csv', ',', 'output2.txt')
csv_to_text.convert()
### Text-CSV Converter

This is a simple Python library to convert text files to CSV format and vice versa. It supports customizable delimiters for text files.

### Features

- Convert delimited text files to CSV.
- Convert CSV files to delimited text.

### Installation

Just download `csvReader.py` and `example.py`

### Usage

1. **Convert Text to CSV:**

```python
from text_csv_converter import TextToCSV

text_to_csv = TextToCSV('input.txt', ',', 'output.csv')
text_to_csv.convert()
```

2. **Convert CSV to Text:**

```python
from text_csv_converter import CSVToText

csv_to_text = CSVToText('output.csv', ',', 'output.txt')
csv_to_text.convert()
```

### Example

Included are `input1.txt` and `input2.csv`:

Run `example.py`:

```sh
python example.py
```

This will create `output1.csv` and `output2.txt`.

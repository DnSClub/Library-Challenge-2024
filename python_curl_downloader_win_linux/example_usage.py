import curl_downloader as vix

url_str = "https://lumpology.com/wp-content/uploads/2023/06/dnsclub.png"
file_output_name = "downloaded_file.png"
if vix.curl_download(file_output_name, url_str):
    print(f"File {file_output_name} was downloaded!")
else:
    print(f"File {file_output_name} was not downloaded")

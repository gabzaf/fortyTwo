import requests, pandas
from bs4 import BeautifulSoup
from datetime import date
from fake_useragent import UserAgent

MAT_ROSE = "5601012011500"
MAT_SPARK = "5601012001310"
BOLOTAS = "5601012004427"
PAPA_FIGOS = "5601012011920"

STORE_NAME = "Continente"
LOCATION = "Portugal"

url_search = "https://www.continente.pt/pesquisa/"

terms = [MAT_SPARK, BOLOTAS, PAPA_FIGOS]

# zip_code = "\n4050-586\n"

# def set_zip_code(term):
#     params = {"q": term, "start": 0, "srule": "Continente", "pmin": 0.01}
#     response = requests.get(url=url_search, params=params)
#     response.raise_for_status()
#     soup = BeautifulSoup(response.text, "html.parser")
#     old_text = soup.find(name="span", class_="delivery-location")
#     old_text.string.replace_with(zip_code)
#     return soup


def set_original_name_ct(name):
    if name == "Mateus Vinho Rosé":
        return "Mateus Rosé Original"
    elif name == "Mateus Sparkling Espumante Rosé Bruto":
        return "Mateus Sparkling Brut Rosé"
    elif name == "Trinca Bolotas Regional Alentejano Vinho Tinto":
        return "Trinca Bolotas Tinto"
    elif name == "Papa Figos DOC Douro Vinho Branco":
        return "Papa Figos Branco"


def get_data(url_search, term):
    '''Get data from url: wine name, capacity, price, currency, date of scraping'''
    
    params = {"q": term, "start": 0, "srule": "Continente", "pmin": 0.01}
    response = requests.get(url=url_search, params=params)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")
    product_link = soup.find(name="a", class_="pwc-tile--description col-tile--description")

    response = requests.get(url=product_link["href"])
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")

    name = soup.find(name="h1", class_="pwc-h3 col-h3 product-name pwc-font--primary-extrabold mb-0").text.strip()
    name = set_original_name_ct(name)
    capacity = soup.find(name="span", class_="ct-pdp--unit col-pdp--unit").text.strip()
    capacity = " ".join(capacity.split(" ")[-2:])
    if capacity[-2:] == "cl":
        capacity = int(capacity[:-3] + "0")
    price_full = soup.find(name="span", class_= "ct-price-formatted").text.strip()
    price = float(price_full[1:].replace(",", "."))
    currency = price_full[0]
    today_date = date.today().strftime("%d/%m/%Y")
    
    return [STORE_NAME, name, capacity, price, currency, today_date, LOCATION]

data = []

for term in terms:
    data.append(get_data(url_search, term))
 
df = pandas.DataFrame(data, \
columns=["Store Name", "Wine Name", "Capacity", "Price", "Currency", "Date of scraping", "Location"])
print(df)
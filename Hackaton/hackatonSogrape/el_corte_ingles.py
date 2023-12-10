import requests, pandas
from bs4 import BeautifulSoup
from datetime import date
from fake_useragent import UserAgent

MAT_ROSE = "5601012011500"
MAT_SPARK = "5601012001310"
BOLOTAS = "5601012004427"
PAPA_FIGOS = "5601012011920"

STORE_NAME = "Supermercado El Corte Inglés"
LOCATION = "Portugal"

terms = [MAT_ROSE, MAT_SPARK, BOLOTAS, PAPA_FIGOS]

url_search = "https://www.elcorteingles.pt/supermercado/pesquisar/"

headers = {"user-agent": UserAgent(browsers=["firefox", "chrome", "safari"]).random}

def set_original_name_ct(name):
    if name == "Vinho Rosé":
        return "Mateus Rosé Original"
    elif name == "Espumante Sparkling Rosé Bruto":
        return "Mateus Sparkling Brut Rosé"
    elif name == "Vinho Tinto Regional do Alentejo":
        return "Trinca Bolotas Tinto"
    elif name == "Vinho Branco do Douro":
        return "Papa Figos Branco"


def get_data(url_search, term):
    '''Get data from url: wine name, capacity, price, currency, date of scraping'''
    
    params = {"term": term, "search": "search", "type_ahead_tab": "panel_all"}
    response = requests.get(url=url_search, params=params, headers=headers)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")
    product_link = soup.find(name="a", class_="link event js-product-link")
    full_link = "https://www.elcorteingles.pt" + product_link["href"]

    response = requests.get(url=full_link, headers=headers)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")

    name_cap = soup.find(name="p").text.replace("\n", " ").strip()
    name = " ".join(name_cap.split(" ")[:-3])
    name = set_original_name_ct(name)
    capacity = " ".join(name_cap.split(" ")[-2:])
    if capacity[-2:] == "cl":
        capacity = int(capacity[:-3] + "0")
    price_full = soup.find(name="div", class_="prices-price _current").text
    price = float(price_full[:-1].replace(",", "."))
    currency = price_full[-1]
    today_date = date.today().strftime("%d/%m/%Y")
    
    return [STORE_NAME, name, capacity, price, currency, today_date, LOCATION]

data = []

for term in terms:
    data.append(get_data(url_search, term))
 
df = pandas.DataFrame(data, \
columns=["Store Name", "Wine Name", "Capacity", "Price", "Currency", "Date of scraping", "Location"])
print(df)
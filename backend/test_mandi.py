import os, requests
from dotenv import load_dotenv

load_dotenv()
api_key = os.getenv("DATA_GOV_API_KEY")
resource_id = os.getenv("AGMARKNET_RESOURCE_ID")

url = f"https://api.data.gov.in/resource/{resource_id}"
params = {
    "api-key": api_key,
    "format": "json",
    "limit": 5
}

try:
    response = requests.get(url, params=params, timeout=15)
    print("Status code:", response.status_code)
    print("Full response:", response.json())
except requests.exceptions.Timeout:
    print("Request timed out — data.gov.in server slow/unresponsive")
except requests.exceptions.ConnectionError as e:
    print("Connection error — network or server issue:", e)
except requests.exceptions.RequestException as e:

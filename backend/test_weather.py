import os, requests
from dotenv import load_dotenv

load_dotenv()
api_key = os.getenv("OPENWEATHER_API_KEY")
print("Key loaded:", api_key[:8] if api_key else "NONE")

city = "Pune"  # change to any city for testing
response = requests.get(
    "https://api.openweathermap.org/data/2.5/weather",
    params={"q": city, "appid": api_key, "units": "metric"}
)
print("Status code:", response.status_code)
print("Full response:", response.json())

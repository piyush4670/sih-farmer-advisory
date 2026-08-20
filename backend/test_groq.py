import os, requests
from dotenv import load_dotenv

load_dotenv()
api_key = os.getenv("GROQ_API_KEY")
print("Key loaded:", api_key[:15] if api_key else "NONE")

response = requests.post(
    "https://api.groq.com/openai/v1/chat/completions",
    headers={"Authorization": f"Bearer {api_key}"},
    json={
        "model": "openai/gpt-oss-120b",
        "messages": [{"role": "user", "content": "Say hello in one line"}]
    }
)
print("Status code:", response.status_code)
print("Full response:", response.json())


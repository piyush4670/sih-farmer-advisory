# SIH Farmer Advisory

A farmer-advisory system for India (Smart India Hackathon project) that combines
curated agricultural knowledge, real-time weather data, and mandi (market) prices
to deliver actionable farming advice through an LLM-powered assistant.

> **Status: early development** — knowledge base and API integration tests are in
> place; the application backend and frontend are not built yet.

## Architecture

Three data sources feed the advisory engine:

```
┌─────────────────┐   ┌──────────────────────┐   ┌──────────────────────┐
│  Knowledge base │   │  OpenWeatherMap      │   │  data.gov.in         │
│  (local .txt)   │   │  (weather)           │   │  Agmarknet (mandi)   │
└────────┬────────┘   └──────────┬───────────┘   └──────────┬───────────┘
         └───────────┬───────────┴──────────────┬───────────┘
                     ▼                          ▼
            Retrieval / context         Weather + price context
                     ▼                          ▼
            ┌────────┴──────────────────────────┴─────────┐
            │              Groq LLM (advisory)            │
            │          e.g. openai/gpt-oss-120b           │
            └──────────────────────┬──────────────────────┘
                                   ▼
                          Farmer-facing app (TBD)
```

## Repository structure

```
backend/
├── knowledge_base/        # 21 curated advisory documents (plain text)
│   ├── rice_cultivation.txt
│   ├── pmkisan_scheme.txt
│   ├── weather_based_farming_advisory.txt
│   └── ...                # see full list below
├── test_groq.py           # Groq LLM API smoke test
├── test_mandi.py          # data.gov.in Agmarknet API smoke test
└── test_weather.py        # OpenWeatherMap API smoke test
```

### Knowledge base contents

| Category | Files |
|---|---|
| **Crops (12)** | rice, wheat, maize, soybean, groundnut, chickpea, cotton, sugarcane, potato, tomato, onion, common pest & disease management |
| **Government schemes (6)** | PM-KISAN, PMFBY (crop insurance), PMKSY (irrigation), Kisan Credit Card, e-NAM (market), SMAM (farm machinery) |
| **General advisories (3)** | weather-based farming, soil health card, soil health & sustainable practices |

Each document is plain text with a `TITLE:` header and structured sections
(sowing windows, fertilizer doses, pest thresholds, eligibility criteria, etc.),
making them easy to chunk and embed for retrieval-augmented generation.

## Setup

```bash
# 1. Install dependencies
pip install requests python-dotenv

# 2. Create a .env file (see required keys below)
cp .env.example .env
```

### Required environment variables

| Variable | Used by | Where to get it |
|---|---|---|
| `GROQ_API_KEY` | `test_groq.py` | https://console.groq.com |
| `OPENWEATHER_API_KEY` | `test_weather.py` | https://openweathermap.org/api |
| `DATA_GOV_API_KEY` | `test_mandi.py` | https://api.data.gov.in |
| `AGMARKNET_RESOURCE_ID` | `test_mandi.py` | https://api.data.gov.in (Agmarknet resource) |

## Running the API tests

Each test verifies one external API end-to-end:

```bash
python backend/test_groq.py      # LLM chat completion
python backend/test_weather.py   # current weather for a city
python backend/test_mandi.py     # latest mandi price records
```

## Roadmap

- [x] Curate knowledge base (crops, schemes, general advisories)
- [x] Verify external APIs (LLM, weather, mandi prices)
- [ ] Backend service (FastAPI) with weather + mandi data layer
- [ ] RAG pipeline (chunk KB → embed → vector store → retrieve → Groq)
- [ ] Farmer-facing frontend (web app)
- [ ] Deployment (Docker, CI)

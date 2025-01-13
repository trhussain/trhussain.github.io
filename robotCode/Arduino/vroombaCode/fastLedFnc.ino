void ledController(std::string typedChar) { 
  Serial.print("called func: ");
  Serial.println(typedChar.c_str());
  if (typedChar == "b") { 
    fillSolid(CRGB::Blue);

  }
  else if (typedChar == "o") { 
    fillSolid(CRGB::Orange);

  }
}

void fillSolid(CRGB color) {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }
    FastLED.show();  // Send the data to the LED strip
}
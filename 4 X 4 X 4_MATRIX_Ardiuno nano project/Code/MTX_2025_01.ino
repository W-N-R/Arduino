// Define the pins for 4 layers (Cathodes)
int layers[4] = {2, 3, 4, 5};

// Define the pins for 16 columns (Anodes)
int columns[16] = {6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3, A4, A5, A6, A7};

void setup() {
    // Set all layer pins as OUTPUT
    for (int i = 0; i < 4; i++) {
        pinMode(layers[i], OUTPUT);
        digitalWrite(layers[i], HIGH);  // Default OFF
    }
    // Set all column pins as OUTPUT
    for (int i = 0; i < 16; i++) {
        pinMode(columns[i], OUTPUT);
        digitalWrite(columns[i], LOW);  // Default OFF
    }
}

// Function to activate a single LED
void lightUp(int layer, int column, int time) {
    digitalWrite(layers[layer], LOW);  // Activate layer (Cathode)
    digitalWrite(columns[column], HIGH);  // Activate column (Anode)
    delay(time);
    digitalWrite(columns[column], LOW);   // Turn OFF column
    digitalWrite(layers[layer], HIGH);   // Turn OFF layer
}

// 🌊 Wave pattern
void waveEffect() {
    for (int col = 0; col < 16; col++) {
        for (int layer = 0; layer < 4; layer++) {
            lightUp(layer, col, 50);
        }
    }
}

// 🌧️ Rainfall pattern
void rainEffect() {
    for (int i = 0; i < 10; i++) {
        int col = random(0, 16);
        for (int layer = 0; layer < 4; layer++) {
            lightUp(layer, col, 100);
        }
    }
}

// 💡 Blinking Cube
void blinkCube() {
    for (int i = 0; i < 3; i++) {
        for (int layer = 0; layer < 4; layer++) {
            digitalWrite(layers[layer], LOW);
        }
        for (int col = 0; col < 16; col++) {
            digitalWrite(columns[col], HIGH);
        }
        delay(500);
        for (int col = 0; col < 16; col++) {
            digitalWrite(columns[col], LOW);
        }
        for (int layer = 0; layer < 4; layer++) {
            digitalWrite(layers[layer], HIGH);
        }
        delay(500);
    }
}

// ⬆️ Expanding Cube
void expandingCube() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            lightUp(i, j, 50);
        }
        delay(200);
    }
}

// 🏗️ Layer-by-Layer lighting
void layerEffect() {
    for (int layer = 0; layer < 4; layer++) {
        digitalWrite(layers[layer], LOW);
        for (int col = 0; col < 16; col++) {
            digitalWrite(columns[col], HIGH);
        }
        delay(300);
        for (int col = 0; col < 16; col++) {
            digitalWrite(columns[col], LOW);
        }
        digitalWrite(layers[layer], HIGH);
    }
}

// ➗ Diagonal Wave
void diagonalWave() {
    for (int d = 0; d < 4; d++) { 
        for (int layer = 0; layer < 4; layer++) {
            int col = (layer + d) % 4 + (4 * ((layer + d) / 4));
            lightUp(layer, col, 200);
        }
    }
}

// 🌀 Spiral Effect
void spiralEffect() {
    int order[] = {0, 1, 5, 4, 3, 7, 11, 10, 14, 15, 13, 9, 8, 12, 6, 2}; 
    for (int layer = 0; layer < 4; layer++) {
        for (int i = 0; i < 16; i++) {
            lightUp(layer, order[i], 150);
        }
    }
}

// ✨ Random Twinkling Stars
void randomStars() {
    for (int i = 0; i < 20; i++) { 
        int layer = random(0, 4);
        int col = random(0, 16);
        lightUp(layer, col, random(50, 300));
    }
}

// 🏢 Rising Towers
void risingTowers() {
    for (int col = 0; col < 16; col++) {
        for (int layer = 0; layer < 4; layer++) {
            lightUp(layer, col, 150);
        }
    }
}

// 🔄 Corner-to-Corner
void cornerToCorner() {
    for (int layer = 0; layer < 4; layer++) {
        lightUp(layer, 0, 100);
        lightUp(layer, 15, 100);
    }
}

// 🔄 Loop to Run Patterns
void loop() {
    waveEffect();
    delay(1000);
    rainEffect();
    delay(1000);
    blinkCube();
    delay(1000);
    expandingCube();
    delay(1000);
    layerEffect();
    delay(1000);
    diagonalWave();
    delay(1000);
    spiralEffect();
    delay(1000);
    randomStars();
    delay(1000);
    risingTowers();
    delay(1000);
    cornerToCorner();
    delay(1000);
}

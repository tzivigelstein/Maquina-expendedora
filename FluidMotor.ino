void setup()
{
    Serial.begin(9600); // No se si funciona el setup en un archivo por separado
    //Averiguar como pasar la clase Serial a la clase Fluid.ino
}

class FluidMotor
{
private:
    boolean on = false;
public:
FluidMotor(){

}
    void sayHello()
    {
        Serial.println("Hello");
    }
};

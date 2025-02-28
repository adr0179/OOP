class Mass:
    def __init__(self, mass, units):
        self.mass = mass
        self.units = units

    def get_mass_in_g(self):
        return self.mass * 1000

    def __gt__(self, other) -> bool:
        if (other.units == "g"):
            return self.get_mass_in_g() > other.mass
        
        if (self.units == "g"):
            return self.mass > other.get_mass_in_g()
        
        return self.mass > other.mass
    
    def __repr__(self) -> str:
        return f'{self.mass}{self.units}'
        
        
mass1 = Mass(10, 'kg')
mass2 = Mass(15, 'g')
mass3 = Mass(16000, 'mg')

print(f'{mass1 = }') 
# expected output: mass1 = 10kg

print(f'{mass2 = }') 
# expected output: mass2 = 15g

print(f'{mass3 = }') 
# expected output: mass3 = 16000mg

print(f'{mass1 > mass2 = }') 
# expected output: mass1 > mass2 = True

print(f'{mass2 > mass3 = }') 
# expected output: mass2 > mass3 = False

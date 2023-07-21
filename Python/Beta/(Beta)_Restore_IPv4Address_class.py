class IPv4Address:
    instances = {}

    def __new__(cls, parts):
        """
        Creates an object representing an IPv4 address

        :param parts: a list of 4 integers
        """
        parts_tuple = tuple(parts)
        if parts_tuple not in cls.instances:
            instance = super().__new__(cls)
            cls.instances[parts_tuple] = instance
            return instance
        else:
            return cls.instances[parts_tuple]

    def __init__(self, parts):
        """
        Initializes an object representing an IPv4 address

        :param parts: a list of 4 integers
        """
        if len(parts) != 4:
            raise ValueError("IPv4 address must have exactly 4 parts")

        for part in parts:
            if not isinstance(part, int):
                raise ValueError("IPv4 address parts must be integers")
            if part < 0 or part > 255:
                raise ValueError("IPv4 address parts must be in the range 0-255")

        if parts[0] == 0:
            raise ValueError("IPv4 address cannot have the first part as 0")

        self._parts = tuple(parts)

    @property
    def parts(self):
        """
        Returns the parts of the IPv4 address
        """
        return self._parts

    def __str__(self):
        """
        Returns the IPv4 address in string format (e.g., "192.168.0.1")
        """
        return ".".join(str(part) for part in self._parts)

    def __repr__(self):
        """
        Returns the official string representation of the IPv4 address object
        """
        return f"IPv4Address({list(self._parts)})"

    def __eq__(self, other):
        """
        Checks if two IPv4 address objects are equal
        """
        if isinstance(other, IPv4Address):
            return self._parts == other._parts
        elif hasattr(other, "parts"):
            raise ValueError("Shouldn't do 'equals to' comparison between IPv4Address and MockAddress")
        return False

    def __ne__(self, other):
        """
        Checks if two IPv4 address objects are not equal
        """
        return not self.__eq__(other)

    def __lt__(self, other):
        """
        Checks if the current IPv4 address is less than the other IPv4 address
        """
        if isinstance(other, IPv4Address):
            return self._parts < other._parts
        elif hasattr(other, "parts"):
            raise ValueError("Shouldn't do 'less than' comparison between IPv4Address and MockAddress")
        raise ValueError("Shouldn't compare IPv4Address with other objects")

    def __le__(self, other):
        """
        Checks if the current IPv4 address is less than or equal to the other IPv4 address
        """
        if isinstance(other, IPv4Address):
            return self._parts <= other._parts
        elif hasattr(other, "parts"):
            raise ValueError("Shouldn't do 'less or equal than' comparison between IPv4Address and MockAddress")
        raise ValueError("Shouldn't compare IPv4Address with other objects")

    def __gt__(self, other):
        """
        Checks if the current IPv4 address is greater than the other IPv4 address
        """
        if isinstance(other, IPv4Address):
            return self._parts > other._parts
        elif hasattr(other, "parts"):
            raise ValueError("Shouldn't do 'greater than' comparison between IPv4Address and MockAddress")
        raise ValueError("Shouldn't compare IPv4Address with other objects")

    def __ge__(self, other):
        """
        Checks if the current IPv4 address is greater than or equal to the other IPv4 address
        """
        if isinstance(other, IPv4Address):
            return self._parts >= other._parts
        elif hasattr(other, "parts"):
            raise ValueError("Shouldn't do 'greater or equal than' comparison between IPv4Address and MockAddress")
        raise ValueError("Shouldn't compare IPv4Address with other objects")

    def __hash__(self):
        """
        Returns the hash value of the IPv4 address object
        """
        return hash(self._parts)

    @classmethod
    def from_string(cls, address_string):
        """
        Creates an IPv4 address object from a string representation (e.g., "192.168.0.1")

        :param address_string: string representation of the IPv4 address
        :return: IPv4Address object
        """
        parts = list(map(int, address_string.split(".")))
        return cls(parts)
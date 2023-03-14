  def isIsomorphic(self, s: str, t: str) -> bool:

        map_s_t = dict()
        map_t_s = dict()

        for c1, c2 in zip(s, t):

            # Aún no existe mapping en ninguno de los dos diccionarios
            if((c1 not in map_s_t) and (c2 not in map_t_s)):
                map_s_t[c1], map_t_s[c2] = c2, c1
            
            # Al menos c1 o c2 ya se encuentra mapeado, la siguiente expresión
            # solo será correcta cuando el mapping sea correcto
            elif(map_s_t.get(c1) != c2) or (map_t_s.get(c2) != c1):
                return False

        return True

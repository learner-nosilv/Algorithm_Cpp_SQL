SELECT animal_id, name
from ANIMAL_INS
where (ANIMAL_TYPE='Dog') and (name like '%el%')
order by 2
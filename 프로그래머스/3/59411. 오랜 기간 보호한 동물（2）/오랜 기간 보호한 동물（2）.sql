SELECT outs.ANIMAL_ID, outs.name
from ANIMAL_OUTS as outs inner join ANIMAL_INS as ins on outs.ANIMAL_ID=ins.ANIMAL_ID
order by (outs.datetime-ins.datetime) desc
limit 2
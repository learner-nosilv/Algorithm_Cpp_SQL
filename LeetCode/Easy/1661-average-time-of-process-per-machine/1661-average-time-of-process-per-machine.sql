SELECT e.machine_id, round(avg(e.timestamp-s.timestamp), 3) as processing_time
FROM Activity as e INNER JOIN Activity as s USING (machine_id, process_id)
WHERE e.activity_type = "end" AND s.activity_type = "start"
GROUP BY 1